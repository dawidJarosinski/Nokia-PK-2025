#pragma once

#include "BaseState.hpp"

namespace ue
{

class ConnectingState : public BaseState
{
public:
    ConnectingState(Context& context);
    void handleAttachAccept() override;
    void handleAttachReject() override;Add commentMore actions
    void handleTimeout() override;
    void handleDisconnected() override;
};

}
