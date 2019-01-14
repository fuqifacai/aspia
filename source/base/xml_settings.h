//
// Aspia Project
// Copyright (C) 2018 Dmitry Chapyshev <dmitry@aspia.ru>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//

#ifndef BASE__XML_SETTINGS_H
#define BASE__XML_SETTINGS_H

#include <QSettings>

#include "base/macros_magic.h"

namespace base {

class XmlSettings
{
public:
    static QSettings::Format registerFormat(
        Qt::CaseSensitivity case_sensitivity = Qt::CaseSensitive);

    static bool readFunc(QIODevice& device, QSettings::SettingsMap& map);
    static bool writeFunc(QIODevice& device, const QSettings::SettingsMap& map);

private:
    DISALLOW_COPY_AND_ASSIGN(XmlSettings);
};

} // namespace base

#endif // BASE__XML_SETTINGS_H
