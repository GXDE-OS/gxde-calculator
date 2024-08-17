/*
 * Copyright (C) 2017 ~ 2017 Deepin Technology Co., Ltd.
 *
 * Author:     rekols <rekols@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <DApplication>
#include <DWidgetUtil>
#include "mainwindow.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication app(argc, argv);
    app.setAttribute(Qt::AA_UseHighDpiPixmaps);
    app.loadTranslator();
    app.setOrganizationName("GXDE");
    app.setApplicationName("gxde-calculator");
    app.setApplicationVersion(DApplication::buildVersion("1.0.1"));
    app.setApplicationAcknowledgementPage("https://gxde.gfdgdxi.top");
    app.setProductIcon(QIcon(":/images/gxde-calculator.svg"));
    app.setProductName(DApplication::translate("MainWindow", "GXDE Calculator"));
    app.setApplicationDescription(DApplication::translate("MainWindow", "GXDE Calculator is a simple and easy to use desktop calculator. It supports addition, subtraction, multiplication and division."));

    MainWindow w;
    w.show();

    if (app.setSingleInstance("gxde-calculator")) {
        Dtk::Widget::moveToCenter(&w);
    }

    return app.exec();
}
