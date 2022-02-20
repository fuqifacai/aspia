//
// Aspia Project
// Copyright (C) 2016-2022 Dmitry Chapyshev <dmitry@aspia.ru>
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

#ifndef CONSOLE__STATUSBAR_H
#define CONSOLE__STATUSBAR_H

#include "base/macros_magic.h"
#include "proto/address_book.pb.h"

#include <QStatusBar>

namespace console {

class StatusBar : public QStatusBar
{
    Q_OBJECT

public:
    explicit StatusBar(QWidget* parent);
    ~StatusBar() override = default;

    void setCurrentComputerGroup(const proto::address_book::ComputerGroup& computer_group);
    void clear();

private:
    DISALLOW_COPY_AND_ASSIGN(StatusBar);
};

} // namespace console

#endif // CONSOLE__STATUSBAR_H
