//Author: Fabien Parent
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
#ifndef __NMV_LOAD_REPORT_DIALOG_H__
#define __NMV_LOAD_REPORT_DIALOG_H__

#include "common/nmv-safe-ptr-utils.h"
#include "nmv-dialog.h"

NEMIVER_BEGIN_NAMESPACE (nemiver)

namespace common {
class UString;
}

using nemiver::common::UString;
using nemiver::common::SafePtr;

class LoadReportDialog : public Dialog {
    struct Priv;
    SafePtr<Priv> m_priv;

public:
    LoadReportDialog (const UString &a_resource_root_path);
    virtual ~LoadReportDialog ();

    UString report_file () const;

};//end class LoadReportDialog

NEMIVER_END_NAMESPACE (nemiver)

#endif //__NMV_LOAD_REPORT_DIALOG_H__
