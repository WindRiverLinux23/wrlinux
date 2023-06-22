IMAGE_INSTALL += "\
    qtbase-examples \
    qtdeclarative-examples \
    qttools-examples \
    qt3d-examples \
    qtapplicationmanager-examples \
    qtcharts-examples \
    qtcoap-examples \
    qtconnectivity-examples \
    qtdatavis3d-examples \
    qtdeviceutilities-examples \
    qtgraphs-examples \
    qtgrpc-examples \
    qthttpserver-examples \
    qtinterfaceframework-examples \
    qtlocation-examples \
    qtmqtt-examples \
    qtmultimedia-examples \
    qtnetworkauth-examples \
    qtopcua-examples \
    qtpositioning-examples \
    qtquick3d-examples \
    qtremoteobjects-examples \
    qtscxml-examples \
    qtserialbus-examples \
    qtserialport-examples \
    qtspeech-examples \
    qtsvg-examples \
    qtvirtualkeyboard-examples \
    qtwayland-examples \
    qtwebchannel-examples \
    qtwebsockets-examples \
"

# from .../layers/meta-qt6/recipes-qt/qt6/qtquick3dphysics_git.bb
# qtquick3dphysics is compatible only with x86[-64] and arm[-64] architectures
IMAGE_INSTALL:append:aarch64 = " qtquick3dphysics-examples"
IMAGE_INSTALL:append:arm = " qtquick3dphysics-examples"
IMAGE_INSTALL:append:x86 = " qtquick3dphysics-examples"
IMAGE_INSTALL:append:x86-64 = " qtquick3dphysics-examples"
