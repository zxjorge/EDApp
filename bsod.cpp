#include "bsod.h"
#include "ui_bsod.h"
#include <QTimer>

#ifdef _WIN32
const bool CAN_BSOD = true;
#include <iostream>
#include <Windows.h>
#include <winternl.h>
using namespace std;
typedef NTSTATUS(NTAPI *pdef_NtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);
typedef NTSTATUS(NTAPI *pdef_RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);
void bsod()
{
    BOOLEAN bEnabled;
    ULONG uResp;
    LPVOID lpFuncAddress = (LPVOID)GetProcAddress(LoadLibraryA("ntdll.dll"), "RtlAdjustPrivilege");
    LPVOID lpFuncAddress2 = (LPVOID)GetProcAddress(GetModuleHandle(L"ntdll.dll"), "NtRaiseHardError");
    pdef_RtlAdjustPrivilege NtCall = (pdef_RtlAdjustPrivilege)lpFuncAddress;
    pdef_NtRaiseHardError NtCall2 = (pdef_NtRaiseHardError)lpFuncAddress2;
    NtCall(19, TRUE, FALSE, &bEnabled);
    NtCall2(STATUS_FLOAT_MULTIPLE_FAULTS, 0, 0, 0, 6, &uResp);
}
#endif
#ifndef _WIN32
const bool CAN_BSOD = false;
void bsod() {

}
#endif

Bsod::Bsod(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::Bsod),
    mainWindow(parent)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->confirmation);
    connect(ui->confirmYes,
            &QPushButton::clicked,
            this,
            [this] {
                if (CAN_BSOD) {
                    ui->stackedWidget->setCurrentWidget(ui->bsod);
                    QTimer::singleShot(500, this, &bsod);
                    QTimer::singleShot(3000, this, [this] {
                        ui->stackedWidget->setCurrentWidget(ui->failedbsod);
                    });
                } else {
                    ui->stackedWidget->setCurrentWidget(ui->cantbsod);
                }
            });
    connect(ui->confirmNo,
            &QPushButton::clicked,
            this,
            [this] {
                ui->stackedWidget->setCurrentWidget(ui->cancelled);
                onSceneEnd();
            });
    connect(ui->cancelledFine,
            &QPushButton::clicked,
            this,
            &Bsod::onSceneEnd);
    connect(ui->cantFine,
            &QPushButton::clicked,
            this,
            &Bsod::onSceneEnd);
    connect(ui->failedFine,
            &QPushButton::clicked,
            this,
            &Bsod::onSceneEnd);
}

void Bsod::onSceneEnd() {

}

Bsod::~Bsod()
{
    delete ui;
}
