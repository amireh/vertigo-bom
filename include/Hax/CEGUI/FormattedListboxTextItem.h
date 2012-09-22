/*
 * This file is part of Vertigo: The Brink of Madness.
 *
 * Vertigo: The Brink of Madness - a cross-platform arcade game powered by Ogre3D.
 * Copyright (C) 2011-2012  Ahmad Amireh <ahmad@amireh.net>
 *
 * Vertigo: The Brink of Madness is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Vertigo: The Brink of Madness is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Vertigo: The Brink of Madness.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef H_FormattedListboxTextItem_H
#define H_FormattedListboxTextItem_H

#include "Hax/Platform.hpp"

#if HAX_PLATFORM == HAX_PLATFORM_APPLE
# include <CoreFoundation/CoreFoundation.h>
#endif

#include "CEGUI/CEGUI.h"

namespace CEGUI
{
//! A ListboxItem based class that can do horizontal text formatiing.
class FormattedListboxTextItem : public ListboxTextItem
{
public:
    //! Constructor
    FormattedListboxTextItem(const String& text,
                    const HorizontalTextFormatting format = HTF_LEFT_ALIGNED,
                    const uint item_id = 0,
                    void* const item_data = 0,
                    const bool disabled = false,
                    const bool auto_delete = true);

    //! Destructor.
    ~FormattedListboxTextItem();

    //! Return the current formatting set.
    HorizontalTextFormatting getFormatting() const;
    /*!
        Set the formatting.  You should call Listbox::handleUpdatedItemData
        after setting the formatting in order to update the listbox.  We do not
        do it automatically since you may wish to batch changes to multiple
        items and multiple calls to handleUpdatedItemData is wasteful.
    */
    void setFormatting(const HorizontalTextFormatting fmt);

    // overriden functions.
    Size getPixelSize(void) const;
    void draw(GeometryBuffer& buffer, const Rect& targetRect,
              float alpha, const Rect* clipper) const;

protected:
    //! Helper to create a FormattedRenderedString of an appropriate type.
    void setupStringFormatter() const;
    //! Current formatting set
    HorizontalTextFormatting d_formatting;
    //! Class that renders RenderedString with some formatting.
    mutable FormattedRenderedString* d_formattedRenderedString;
    //! Tracks target area for rendering so we can reformat when needed
    mutable Size d_formattingAreaSize;
};

// allocates and returns a new ListboxTextItem
FormattedListboxTextItem* ceguiLua_createFormattedListboxTextItem(
  const String& text,
  const HorizontalTextFormatting format,
  const uint item_id,
  void* const item_data,
  const bool disabled,
  const bool auto_delete);
}

#endif
