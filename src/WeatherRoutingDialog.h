/***************************************************************************
 *
 * Project:  OpenCPN Weather Routing plugin
 * Author:   Sean D'Epagnier
 *
 ***************************************************************************
 *   Copyright (C) 2013 by Sean D'Epagnier                                 *
 *   sean@depagnier.com                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.             *
 ***************************************************************************
 */

#ifndef _WEATHER_ROUTING_H_
#define _WEATHER_ROUTING_H_


#include <wx/treectrl.h>
#include <wx/fileconf.h>

#include "WeatherRoutingUI.h"
#include "ConfigurationDialog.h"
#include "SettingsDialog.h"

class weather_routing_pi;
class BoatDialog;
class BatchDialog;
class RouteDialog;
class GribUIDialog;

class WeatherRoutingDialog : public WeatherRoutingDialogBase
{
public:
    WeatherRoutingDialog( wxWindow *parent, weather_routing_pi &plugin );
    ~WeatherRoutingDialog( );

    void Reset();

    void RenderRouteMap(ocpnDC &dc, PlugIn_ViewPort &vp);
    RouteMapOverlay m_RouteMapOverlay;
    ConfigurationDialog m_ConfigurationDialog;

private:
    void OnUpdateEnd( wxCommandEvent& event );
    void OnCompute( wxCommandEvent& event );
    void OnReset( wxCommandEvent& event );
    void OnSettings( wxCommandEvent& event );
    void OnConfiguration( wxCommandEvent& event );
    void OnBoat( wxCommandEvent& event );
    void OnPlot( wxCommandEvent& event );
    void OnExport( wxCommandEvent& event );
    void OnBatch ( wxCommandEvent& event );
    void OnRoutes ( wxCommandEvent& event );
    void OnInformation( wxCommandEvent& event );
    void OnStatistics( wxCommandEvent& event );
    void OnClose( wxCommandEvent& event );
    void OnComputationTimer( wxTimerEvent & );

    void UpdateStatistics();

    void UpdateEnd();

    void SetStartDateTime(wxDateTime datetime);
    void SyncToBoatPosition( wxCommandEvent& event );
    void SyncToGribTime( wxCommandEvent& event );

    void Start();
    void Stop();
    void ReconfigureRouteMap();
    void SetRouteMapOverlaySettings();

    SettingsDialog m_SettingsDialog;

    weather_routing_pi   &Plugin;

    bool m_bComputing;

    BoatDialog *m_pBoatDialog;
    BatchDialog *m_pBatchDialog;
    RouteDialog *m_pRouteDialog;

    wxTimer m_tCompute;

    wxTimeSpan m_RunTime;
    wxDateTime m_StartTime;
};

#endif
