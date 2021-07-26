/*
	Copyright (C) 2012 - 2021
	Part of the Battle for Wesnoth Project https://www.wesnoth.org/

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY.

	See the COPYING file for more details.
*/

#define GETTEXT_DOMAIN "wesnoth-lib"

#include "gui/core/placer.hpp"

#include <cassert>
#include "gui/core/placer/horizontal_list.hpp"
#include "gui/core/placer/vertical_list.hpp"


namespace gui2
{

placer_base* placer_base::build(const grow_direction grow_direction,
						  const unsigned parallel_items)
{
	switch(grow_direction.v) {
		case grow_direction::horizontal:
			return new implementation::placer_horizontal_list(parallel_items);
		case grow_direction::vertical:
			return new implementation::placer_vertical_list(parallel_items);
	};

	throw "UNREACHABLE CODE REACHED";
}

placer_base::~placer_base()
{
}

} // namespace gui2
