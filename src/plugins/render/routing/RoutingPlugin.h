//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2010      Siddharth Srivastava <akssps011@gmail.com>
// Copyright 2010      Dennis Nienhüser <earthwings@gentoo.org>
//

#ifndef MARBLE_ROUTINGPLUGIN_H
#define MARBLE_ROUTINGPLUGIN_H

#include "AbstractFloatItem.h"

namespace Marble
{
class RoutingPluginPrivate;
class PositionProviderPlugin;

class RoutingPlugin : public AbstractFloatItem
{
    Q_OBJECT

    Q_INTERFACES( Marble::RenderPluginInterface )

    MARBLE_PLUGIN( RoutingPlugin )

public:
    explicit RoutingPlugin( const QPointF &point = QPointF( -10, -10 ) );

    ~RoutingPlugin();

    QStringList backendTypes() const;

    void initialize();

    bool isInitialized() const;

    QString name() const;

    QString guiString() const;

    QString nameId() const;

    QString description() const;

    QIcon icon() const;

    bool eventFilter( QObject *object, QEvent *event );

private:    
    /** Disable zoom buttons if needed */
    Q_PRIVATE_SLOT( d, void updateZoomButtons() )

    /** Disable zoom buttons if needed */
    Q_PRIVATE_SLOT( d, void updateZoomButtons( int ) )

    /** Switch source/destination of the route and recalculate it */
    Q_PRIVATE_SLOT( d, void reverseRoute() )

    /** Toggles guidance mode */
    Q_PRIVATE_SLOT( d, void toggleGuidanceMode( bool enabled ) )

    /** sets time and distance remaining to reach the destination */
    Q_PRIVATE_SLOT( d, void updateDestinationInformation( qint32, qreal ) )

    /** Update the checked state of the position tracking button */
    Q_PRIVATE_SLOT( d, void updateGpsButton( PositionProviderPlugin *activePlugin ) )

    /** Activate or deactivate position tracking */
    Q_PRIVATE_SLOT( d, void togglePositionTracking( bool enabled ) )

    Q_PRIVATE_SLOT( d, void updateGuidanceModeButton() );

    RoutingPluginPrivate* const d;
};

}

#endif // MARBLE_ROUTINGPLUGIN_H
