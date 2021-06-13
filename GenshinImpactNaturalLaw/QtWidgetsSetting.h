#pragma once
#include <vector>
#include <QPropertyAnimation>
#include <QScrollBar>
#include <QScrollArea>
#include <QMouseEvent>
#include <QWidget>
#include "ui_QtWidgetsSetting.h"
#include "SettingData.h"

class QtWidgetsSetting : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsSetting(QWidget *parent = Q_NULLPTR);
	~QtWidgetsSetting();

private:
	Ui::QtWidgetsSetting ui;

public:
	SettingData *setting = nullptr;

private:
	QPoint m_Press;
	QPoint m_Move;
	bool leftBtnClk = false;
private:
	std::vector<QPushButton*> UIButtonList;
	std::vector<QLabel*> ScrollLabelList;
private:
	void uiConnectButton();
private:
	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

public slots:
	void SetSetting(SettingData *setting);

private slots:
	void CloseSelf();
	void Cancel();
	void OK();
	void SwitchOptions();

signals:
	void SendSettingToMainWidgets(SettingData *setting);
	void SendCloseSelfSignalToMainWidgets();
};
