/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_LIST_VIEW_SKINLET_H
#define QSK_LIST_VIEW_SKINLET_H

#include "QskGlobal.h"
#include "QskScrollViewSkinlet.h"

class QskListView;
class QskListViewNode;
class QskTextNode;

class QMarginsF;
class QSizeF;
class QRectF;
class QSGTransformNode;

class QSK_EXPORT QskListViewSkinlet : public QskScrollViewSkinlet
{
    Q_GADGET

    using Inherited = QskScrollViewSkinlet;

public:
    Q_INVOKABLE QskListViewSkinlet( QskSkin* = nullptr );
    virtual ~QskListViewSkinlet();

protected:
    enum NodeRole
    {
        TextRole,
        GraphicRole
    };

    virtual QSGNode* updateContentsNode(
        const QskScrollView*, QSGNode* ) const override;

    virtual QSGNode* updateCellNode( const QskListView*,
        QSGNode*, const QRectF&, int row, int col ) const;

private:
    void updateForegroundNodes( const QskListView*, QskListViewNode* ) const;
    void updateBackgroundNodes( const QskListView*, QskListViewNode* ) const;

    void updateVisisbleForegroundNodes(
        const QskListView*, QskListViewNode*,
        int rowMin, int rowMax, int colMin, int colMax,
        const QMarginsF& margin, bool forward ) const;

    QSGTransformNode* updateForegroundNode( const QskListView*,
        QSGNode* parentNode, QSGTransformNode* cellNode,
        int row, int col, const QSizeF&, bool forward ) const;
};

#endif
