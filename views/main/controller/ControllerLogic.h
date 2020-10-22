//
// Created by Iron Tony on 22/10/2020.
//

#ifndef ATM_CONTROLLERLOGIC_H
#define ATM_CONTROLLERLOGIC_H


// Liskov Substitution Principle: *Exists*
// Me:
class ControllerLogic {
public:
    virtual void onBtnEnterClicked() {}
    virtual void onBtnCancelClicked() {}
    virtual void onBtnClearClicked() {}
    virtual void onBtn0Clicked() {}
    virtual void onBtn1Clicked() {}
    virtual void onBtn2Clicked() {}
    virtual void onBtn3Clicked() {}
    virtual void onBtn4Clicked() {}
    virtual void onBtn5Clicked() {}
    virtual void onBtn6Clicked() {}
    virtual void onBtn7Clicked() {}
    virtual void onBtn8Clicked() {}
    virtual void onBtn9Clicked() {}
    virtual void onBtnPointClicked() {}
    virtual void onBtnMoneyInClicked() {}
    virtual void onBtnCheckClicked() {}
    virtual void onBtnCardClicked() {}
    virtual void onBtnMoneyOutClicked() {}

protected:
    ~ControllerLogic() = default;
};


#endif //ATM_CONTROLLERLOGIC_H
