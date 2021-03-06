/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#include "QskTextLabelSkinlet.h"
#include "QskTextLabel.h"
#include "QskTextOptions.h"

QskTextLabelSkinlet::QskTextLabelSkinlet( QskSkin* skin ):
    Inherited( skin )
{
    setNodeRoles( { TextRole } );
}

QskTextLabelSkinlet::~QskTextLabelSkinlet() = default;

QRectF QskTextLabelSkinlet::subControlRect(
    const QskSkinnable* skinnable, QskAspect::Subcontrol subControl ) const
{       
    const auto label = static_cast< const QskTextLabel* >( skinnable );
    
    if ( subControl == QskTextLabel::Text )
    {
        return textRect( label );
    }

    return Inherited::subControlRect( skinnable, subControl );
}

QRectF QskTextLabelSkinlet::textRect( const QskTextLabel* label ) const
{
    return label->contentsRect();
}

QSGNode* QskTextLabelSkinlet::updateSubNode( const QskSkinnable* skinnable,
    quint8 nodeRole, QSGNode* node ) const
{
    const auto label = static_cast< const QskTextLabel* >( skinnable );

    switch( nodeRole )
    {
        case TextRole:
            return updateTextNode( label, node );

        default:
            return nullptr;
    }
}

QSGNode* QskTextLabelSkinlet::updateTextNode(
    const QskTextLabel* label, QSGNode* node ) const
{
    return QskSkinlet::updateTextNode( label, node, 
        label->text(), label->textOptions(), QskTextLabel::Text );
}

#include "moc_QskTextLabelSkinlet.cpp"
