/***************************************************************************
 * img_settings.h
 *
 * Copyright (C) 2005 - 2011 Florian Richter
 ***************************************************************************/
/*
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SMC_IMG_SETTINGS_H
#define SMC_IMG_SETTINGS_H

#include "../core/global_basic.h"
#include "../core/file_parser.h"
#include "../video/gl_surface.h"
#include "../core/math/rect.h"

namespace SMC
{

/* *** *** *** *** *** *** cImage_settings_data *** *** *** *** *** *** *** *** *** *** *** */

class cImage_settings_data
{
public:
	cImage_settings_data( void );
	~cImage_settings_data( void );

	// returns the best surface size for the current resolution
	cSize_Float Get_Surface_Size( const SDL_Surface *sdl_surface ) const;
	// Apply settings to an image
	void Apply( cGL_Surface *image ) const;
	// Apply base settings
	void Apply_Base( const cImage_settings_data *base_settings_data );

	// base image/settings path
	std::string m_base;
	// inherit base settings
	bool m_base_settings;

	// internal drawing offset
	int m_int_x;
	int m_int_y;
	// collision rect
	GL_rect m_col_rect;
	// width
	int m_width;
	// height
	int m_height;
	// rotation
	int m_rotation_x, m_rotation_y, m_rotation_z;
	// texture mipmapping
	bool m_mipmap;

	// editor tags
	std::string m_editor_tags;
	// name
	std::string m_name;
	// sprite type
	int m_type;
	// ground type
	GroundType m_ground_type;
	// author
	std::string m_author;
	// obsolete
	bool m_obsolete;
};

/* *** *** *** *** *** *** cImage_settings *** *** *** *** *** *** *** *** *** *** *** */

// Image Settings Handler
// Inherits from cFile_parser
class cImage_settings : public cFile_parser
{
public:
	cImage_settings( void );
	virtual ~cImage_settings( void );

	/* Returns the settings from the given file
	 * load_base_settings : if set will overwrite settings with all base settings if available
	 * The returned settings data should be deleted if not used anymore
	*/
	cImage_settings_data *Get( const std::string &filename, bool load_base_settings = 1 );

	// Handles the Image Settings Line
	virtual bool HandleMessage( const std::string *parts, unsigned int count, unsigned int line );

	// temp settings used for loading
	cImage_settings_data *m_settings_temp;
	// load base settings
	bool m_load_base;
};

/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */

// Image Settings Handler class
extern cImage_settings *pSettingsParser;

/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */

} // namespace SMC

#endif
