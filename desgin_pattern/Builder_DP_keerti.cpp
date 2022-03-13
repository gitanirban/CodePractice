//
// Created by anidu on 13-03-2022.
//

#ifndef BUILDER_DP_KEERTI_DESKTOP_H
#define BUILDER_DP_KEERTI_DESKTOP_H

#include <string>
#include <iostream>
using namespace std;

class Desktop{
    string m_monitor;
    string m_keyboard;
    string m_processor;
public:
    void setMonitor(string  rArg){ m_monitor = rArg;   }
    void setKeyboard(string  rArg){ m_keyboard = rArg;   }
    void setProcessor(string  rArg){ m_processor = rArg;   }
    void showSpecs(){
        cout << "Monitor : " << m_monitor << endl;
        cout << "KeyBoard : " << m_keyboard << endl;
        cout << "Keyboard : " << m_processor << endl;
    }
};
#endif //BUILDER_DP_KEERTI_DESKTOP_H



//
// Created by anidu on 13-03-2022.
//

#ifndef BUILDER_DP_KEERTI_DESKTOPBUILDER_H
#define BUILDER_DP_KEERTI_DESKTOPBUILDER_H
#include "desktop.h"
class DesktopBuilder{
protected:
    Desktop * m_pDesktop;
public:
    DesktopBuilder(){ m_pDesktop = new Desktop(); }
    virtual void buildMonitor() = 0;
    virtual void buildKeyboard() = 0;
    virtual void buildProcessor() = 0;
    virtual Desktop * getDesktop() { return m_pDesktop;}
};
#endif //BUILDER_DP_KEERTI_DESKTOPBUILDER_H




//
// Created by anidu on 13-03-2022.
//
#include "string.h"
#include "DesktopBuilder.h"
#ifndef BUILDER_DP_KEERTI_DELLDESKTOPBUILDER_H
#define BUILDER_DP_KEERTI_DELLDESKTOPBUILDER_H

class DellDesktopBuilder : public DesktopBuilder{
     void buildMonitor(){m_pDesktop->setMonitor( "Dell Monitor");  }
     void buildKeyboard(){m_pDesktop->setKeyboard( "Dell Keyboard"); }
     void buildProcessor(){m_pDesktop->setProcessor( "Dell Processor"); }
};
#endif //BUILDER_DP_KEERTI_DELLDESKTOPBUILDER_H




//
// Created by anidu on 13-03-2022.
//

#ifndef BUILDER_DP_KEERTI_HPDESKTOPBUILDER_H
#define BUILDER_DP_KEERTI_HPDESKTOPBUILDER_H
//
// Created by anidu on 13-03-2022.
//
#include "string.h"
#include "DesktopBuilder.h"

class HPDesktopBuilder : public DesktopBuilder{
    void buildMonitor(){m_pDesktop->setMonitor( "HP Monitor");  }
    void buildKeyboard(){m_pDesktop->setKeyboard( "HP Keyboard"); }
    void buildProcessor(){m_pDesktop->setProcessor( "HP Processor"); }
};

#endif //BUILDER_DP_KEERTI_HPDESKTOPBUILDER_H



#include <iostream>
#include "HPDesktopBuilder.h"
#include "DellDesktopBuilder.h"
#include "DesktopDirector.h"

int main() {
    HPDesktopBuilder * pHpDesktopBuilder = new HPDesktopBuilder();
    DellDesktopBuilder *pDellDesktopBuilder = new DellDesktopBuilder();

    DesktopDirector * pDir1 = new DesktopDirector(pHpDesktopBuilder);
    DesktopDirector * pDir2 = new DesktopDirector(pDellDesktopBuilder);

    Desktop * desk1 = pDir1->BuildDesktop();
    Desktop * desk2 = pDir2->BuildDesktop();

    desk1->showSpecs();
    desk2->showSpecs();


    return 0;
}
