//
// PROJECT:         Aspia Remote Desktop
// FILE:            ui/system_info/output.h
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_UI__SYSTEM_INFO__OUTPUT_H
#define _ASPIA_UI__SYSTEM_INFO__OUTPUT_H

//
// To display the information, we use a table representation. Each category is a separate table.
// Each table has a title and a header. Table header contains column titles.
// Categories fall into two types:
// 1. Generic table. Contains unlimited number of columns and rows.
// 2. Table of parameters / values. Contains only 2 columns: a parameter and a value.
//    Parameters can be merged into groups.
//
// The structure of the document is generated by calling methods sequentially.
//
// StartDocument()
//     StartTableGroup(<group_name>)
//         StartTable(<table_name>)
//             StartTableHeader()
//                 AddHeaderItem(<column_name1>, <column_width1>)
//                 ...
//                 AddHeaderItem(<column_nameN>, <column_widthN>)
//             EndTableHeader()
//             StartRow(<icon_id>)
//                 AddValue(<value1>, <unit1>)
//                 ...
//                 AddValue(<valueN>, <unitN>)
//             EndRow()
//         EndTable()
//     EndTableGroup()
//     StartTable(<table_name>)
//         StartTableHeader()
//             AddHeaderItem(<column_name1>, <column_width1>)
//             AddHeaderItem(<column_name2>, <column_width2>)
//         EndTableHeader()
//         StartGroup(<name>, <icon_id>)
//             AddParam(<icon_id1>, <parameter_name1>, <value1>, <unit1>)
//             ...
//             AddParam(<icon_idN>, <parameter_nameN>, <valueN>, <unitN>)
//         EndGroup()
//     EndTable()
// EndDocument()
//

#include "protocol/category.h"
#include "ui/system_info/column_list.h"
#include "ui/system_info/group.h"
#include "ui/system_info/table.h"
#include "ui/system_info/value.h"
#include "ui/system_info/row.h"

namespace aspia {

class Output
{
public:
    virtual ~Output() = default;

private:
    friend class ReportCreator;
    friend class Table;
    friend class Group;
    friend class Row;

    virtual void StartDocument() = 0;
    virtual void EndDocument() = 0;

    virtual void StartTableGroup(std::string_view name) = 0;
    virtual void EndTableGroup() = 0;

    virtual void StartTable(Category* category) = 0;
    virtual void EndTable() = 0;

    virtual void AddColumns(const ColumnList& column_list) = 0;

    virtual void StartGroup(std::string_view name) = 0;
    virtual void EndGroup() = 0;
    virtual void AddParam(std::string_view param, const Value& value) = 0;

    virtual void StartRow() = 0;
    virtual void EndRow() = 0;
    virtual void AddValue(const Value& value) = 0;
};

} // namespace aspia

#endif // _ASPIA_UI__SYSTEM_INFO__OUTPUT_H
