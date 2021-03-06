/*
 * resizemap.h
 * Copyright 2009, Thorbjørn Lindeijer <thorbjorn@lindeijer.nl>
 *
 * This file is part of Tiled.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QSize>
#include <QUndoCommand>

namespace Tiled {

class MapDocument;

/**
 * Undo command that resizes a map. This command does not touch any of the
 * map layers. See ResizeLayer if you want that.
 */
class ResizeMap : public QUndoCommand
{
public:
    ResizeMap(MapDocument *mapDocument,
              QSize size,
              QUndoCommand *parent = nullptr);

    void undo() override;
    void redo() override;

private:
    void swapSize();

    MapDocument *mMapDocument;
    QSize mSize;
};

} // namespace Tiled
