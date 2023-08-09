// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.2
import MediaViewer
import QtQuick.Controls


Window {
    width: 640
    height: 480


    visible: true
    title: "MediaViewer"

    StackView{
    id: loader
    anchors.fill: parent
    initialItem: "home.qml"

    }

    /*Screen01 {
        id: mainScreen
    }*/

}

