/* This file is generated by glib-genmarshal, do not modify it. This code is licensed under the same license as the containing project. Note that it links to GLib, so must comply with the LGPL linking clauses. */
#ifndef __V3270FT_MARSHAL_H__
#define __V3270FT_MARSHAL_H__

#include <glib-object.h>

G_BEGIN_DECLS

/* VOID:POINTER,POINTER (src/filetransfer/marshal:1) */
extern
void v3270ft_VOID__POINTER_POINTER (GClosure     *closure,
                                    GValue       *return_value,
                                    guint         n_param_values,
                                    const GValue *param_values,
                                    gpointer      invocation_hint,
                                    gpointer      marshal_data);

/* VOID:VOID,BOOLEAN (src/filetransfer/marshal:2) */
extern
void v3270ft_VOID__VOID_BOOLEAN (GClosure     *closure,
                                 GValue       *return_value,
                                 guint         n_param_values,
                                 const GValue *param_values,
                                 gpointer      invocation_hint,
                                 gpointer      marshal_data);

/* VOID:VOID,OBJECT (src/filetransfer/marshal:3) */
extern
void v3270ft_VOID__VOID_OBJECT (GClosure     *closure,
                                GValue       *return_value,
                                guint         n_param_values,
                                const GValue *param_values,
                                gpointer      invocation_hint,
                                gpointer      marshal_data);

/* VOID:UINT,POINTER (src/filetransfer/marshal:4) */
#define v3270ft_VOID__UINT_POINTER	g_cclosure_marshal_VOID__UINT_POINTER

/* VOID:VOID,POINTER (src/filetransfer/marshal:5) */
extern
void v3270ft_VOID__VOID_POINTER (GClosure     *closure,
                                 GValue       *return_value,
                                 guint         n_param_values,
                                 const GValue *param_values,
                                 gpointer      invocation_hint,
                                 gpointer      marshal_data);


G_END_DECLS

#endif /* __V3270FT_MARSHAL_H__ */
