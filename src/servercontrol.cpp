#include "servercontrol.h"
#include "mainwindow.h"
#include "VirtualMachine.hpp"
#include "qtutilities.h"

ServerControl *ServerControl::instance = nullptr;

ServerControl::ServerControl(QObject *parent) : QObject(parent)
{
    instance = this;
    serverInfoPane = MainWindow::getUi()->findChild<QObject*>("serverInfoPane");
    serverQuickControlPane_ON = MainWindow::getUi()->findChild<QObject*>("serverQuickControlPane_ON");
    serverQuickControlPane_OFF = MainWindow::getUi()->findChild<QObject*>("serverQuickControlPane_OFF");
    serverInfoPane_button_ON = MainWindow::getUi()->findChild<QObject*>("serverInfoPane_button_ON");
    serverInfoPane_button_OFF = MainWindow::getUi()->findChild<QObject*>("serverInfoPane_button_OFF");

    connect(this, &ServerControl::readyToUpdateServerControlUI, this, &ServerControl::updateServerControlUI);
    connect(this, &ServerControl::readyToDeleteServer, this, &ServerControl::deleteServer);
}

ServerControl *ServerControl::getInstance()
{
    return instance;
}

void ServerControl::updateServerControlUI(const QString &machineName)
{
    auto machine = PackageManager::getInstance()->getMachines()->back().getInstance();
//    remove after DEMO
//    auto machine = VirtualMachine::getVirtualMachine(machineName.toStdWString());
    if(machine->getStatus() == VirtualMachineState::PoweredOff)
    {
        QtUtilities::setVisible(serverQuickControlPane_OFF, true);
        QtUtilities::setVisible(serverQuickControlPane_ON, false);
        QtUtilities::setVisible(serverInfoPane_button_ON, true);
        QtUtilities::setVisible(serverInfoPane_button_OFF, false);
    }
    else if(machine->getStatus() == VirtualMachineState::Running)
    {
        QtUtilities::setVisible(serverQuickControlPane_OFF, false);
        QtUtilities::setVisible(serverQuickControlPane_ON, true);
        QtUtilities::setVisible(serverInfoPane_button_ON, false);
        QtUtilities::setVisible(serverInfoPane_button_OFF, true);
    }
    else
    {
        QtUtilities::setVisible(serverQuickControlPane_OFF, false);
        QtUtilities::setVisible(serverQuickControlPane_ON, false);
        QtUtilities::setVisible(serverInfoPane_button_ON, false);
        QtUtilities::setVisible(serverInfoPane_button_OFF, false);
    }
}

void ServerControl::deleteServer(const QString &machineName)
{
    PackageManager::getInstance()->DeleteMachine(PackageManager::getInstance()->getMachines()->back().getName());
//    remove after DEMO
//    PackageManager::getInstance()->DeleteMachine(machineName.toStdWString());
}
