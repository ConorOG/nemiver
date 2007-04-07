//Author: Jonathon Jongsma
/*
 *This file is part of the Nemiver project
 *
 *Nemiver is free software; you can redistribute
 *it and/or modify it under the terms of
 *the GNU General Public License as published by the
 *Free Software Foundation; either version 2,
 *or (at your option) any later version.
 *
 *Nemiver is distributed in the hope that it will
 *be useful, but WITHOUT ANY WARRANTY;
 *without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *See the GNU General Public License for more details.
 *
 *You should have received a copy of the
 *GNU General Public License along with Nemiver;
 *see the file COPYING.
 *If not, write to the Free Software Foundation,
 *Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *See COPYRIGHT file copyright information.
 */

#include <vector>
#include <glib/gi18n.h>
#include <libglademm.h>
#include <gtkmm/dialog.h>
#include "common/nmv-exception.h"
#include "common/nmv-env.h"
#include "common/nmv-ustring.h"
#include "nmv-set-breakpoint-dialog.h"
#include "nmv-ui-utils.h"

using namespace std ;
using namespace nemiver::common ;

namespace nemiver {
class SetBreakpointDialog::Priv {
    public:
    Gtk::Entry *entry_filename ;
    Gtk::Entry *entry_line;
    Gtk::Button *okbutton ;

public:
    Priv (const Glib::RefPtr<Gnome::Glade::Xml> &a_glade) :
        entry_filename (0),
        entry_line (0),
        okbutton (0)
    {

        okbutton =
            ui_utils::get_widget_from_glade<Gtk::Button> (a_glade, "okbutton") ;
        THROW_IF_FAIL (okbutton) ;
        okbutton->set_sensitive (false) ;

        entry_filename =
            ui_utils::get_widget_from_glade<Gtk::Entry>
                (a_glade, "entry_filename") ;
        entry_filename->signal_changed ().connect (sigc::mem_fun
                (*this, &Priv::on_text_changed_signal)) ;

        entry_line =
            ui_utils::get_widget_from_glade<Gtk::Entry>
                (a_glade, "entry_line") ;
        entry_line->signal_changed ().connect (sigc::mem_fun
                (*this, &Priv::on_text_changed_signal)) ;
    }

    void on_text_changed_signal ()
    {
        NEMIVER_TRY

        THROW_IF_FAIL (entry_filename) ;
        THROW_IF_FAIL (entry_line) ;

        // make sure there's something in both entries
        if (!entry_filename->get_text ().empty () &&
                !entry_line->get_text ().empty ()) {
            okbutton->set_sensitive (true) ;
        } else {
            okbutton->set_sensitive (false) ;
        }
        NEMIVER_CATCH
    }
};//end class SetBreakpointDialog::Priv

SetBreakpointDialog::SetBreakpointDialog (const UString &a_root_path) :
    Dialog (a_root_path, "setbreakpoint.glade", "setbreakpointdialog")
{
    m_priv.reset (new Priv (glade ())) ;
}

SetBreakpointDialog::~SetBreakpointDialog ()
{
}

UString
SetBreakpointDialog::file_name () const
{
    NEMIVER_TRY

    THROW_IF_FAIL (m_priv) ;
    THROW_IF_FAIL (m_priv->entry_filename) ;

    NEMIVER_CATCH
    return m_priv->entry_filename->get_text () ;
}

void
SetBreakpointDialog::file_name (const UString &a_name)
{
    NEMIVER_TRY

    THROW_IF_FAIL (m_priv) ;
    THROW_IF_FAIL (m_priv->entry_filename) ;
    m_priv->entry_filename->set_text (a_name) ;

    NEMIVER_CATCH
}

UString
SetBreakpointDialog::line_number () const
{
    NEMIVER_TRY

    THROW_IF_FAIL (m_priv) ;
    THROW_IF_FAIL (m_priv->entry_line) ;

    NEMIVER_CATCH
    return m_priv->entry_line->get_text () ;
}

void
SetBreakpointDialog::line_number (int a_line)
{
    NEMIVER_TRY

    THROW_IF_FAIL (m_priv) ;
    THROW_IF_FAIL (m_priv->entry_line) ;
    m_priv->entry_line->set_text (UString::from_int(a_line)) ;

    NEMIVER_CATCH
}

}//end namespace nemiver

