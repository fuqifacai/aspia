//
// PROJECT:         Aspia Remote Desktop
// FILE:            ui/drive_list.h
// LICENSE:         See top-level directory
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_UI__DRIVE_LIST_H
#define _ASPIA_UI__DRIVE_LIST_H

#include "base/macros.h"
#include "proto/file_transfer_session.pb.h"

#include <atlbase.h>
#include <atlapp.h>
#include <atlwin.h>
#include <atlctrls.h>
#include <atlmisc.h>
#include <memory>

namespace aspia {

class UiDriveList : public CWindowImpl<UiDriveList, CComboBoxEx>
{
public:
    static const int kInvalidObjectIndex = -1;
    static const int kComputerObjectIndex = -2;
    static const int kCurrentFolderObjectIndex = -3;

    UiDriveList() = default;
    ~UiDriveList() = default;

    bool CreateDriveList(HWND parent, int control_id);

    void Read(std::unique_ptr<proto::DriveList> list);

    bool HasDriveList() const;
    bool IsValidObjectIndex(int object_index) const;
    void SelectObject(int object_index);
    int SelectedObject() const;
    const proto::DriveListItem& Object(int object_index) const;
    const proto::DriveList& DriveList() const;
    void SetCurrentPath(const std::string& path);
    std::string ObjectPath(int object_index) const;

private:
    BEGIN_MSG_MAP(UiDriveList)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
    END_MSG_MAP()

    LRESULT OnCreate(UINT message, WPARAM wparam, LPARAM lparam, BOOL& handled);

    int GetItemIndexByObjectIndex(int object_index) const;
    int GetKnownObjectIndex(const std::string& path) const;

    std::unique_ptr<proto::DriveList> list_;
    CImageListManaged imagelist_;

    DISALLOW_COPY_AND_ASSIGN(UiDriveList);
};

} // namespace aspia

#endif // _ASPIA_UI__DRIVE_LIST_H
