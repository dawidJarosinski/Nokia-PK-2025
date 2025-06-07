#pragma once

#include "BaseState.hpp"

namespace ue
{

class ConnectedState : public BaseState
{
public:
    ConnectedState(Context& context);
    void handleDisconnected() override;
    void handleSmsReceived(common::PhoneNumber from, std::string text) override;
private:
  void showMainMenu();
};
}
