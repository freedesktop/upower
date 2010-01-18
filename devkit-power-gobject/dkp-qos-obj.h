/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2009 Richard Hughes <richard@hughsie.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#if !defined (__DEVICEKIT_POWER_H_INSIDE__) && !defined (DKP_COMPILATION)
#error "Only <devicekit-power.h> can be included directly."
#endif

#ifndef __DKP_QOS_OBJ_H__
#define __DKP_QOS_OBJ_H__

#include <glib.h>
#include <devkit-power-gobject/dkp-enum.h>

G_BEGIN_DECLS

typedef struct
{
	guint			 uid;
	guint			 pid;
	gchar			*sender; /* only used in the daemon */
	gchar			*cmdline;
	guint			 cookie;
	guint64			 timespec;
	gboolean		 persistent;
	DkpQosType		 type;
	gint			 value;
} DkpQosObj;

/* compat */
typedef DkpQosObj UpQosObj;

DkpQosObj	*dkp_qos_obj_new		(void);
void		 dkp_qos_obj_free		(DkpQosObj		*obj);
DkpQosObj	*dkp_qos_obj_copy		(const DkpQosObj	*cobj);
gboolean	 dkp_qos_obj_print		(const DkpQosObj	*obj);
gboolean	 dkp_qos_obj_equal		(const DkpQosObj	*obj1,
						 const DkpQosObj	*obj2);

G_END_DECLS

#endif /* __DKP_QOS_OBJ_H__ */

