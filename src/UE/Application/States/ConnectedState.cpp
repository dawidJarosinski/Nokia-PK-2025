#include "ConnectedState.hpp"
#include "NotConnectedState.hpp"
#include "ViewingSmsListState.hpp"Add commentMore actions
#include <vector>

namespace ue
{

    ConnectedState::ConnectedState(Context &context)
        : BaseState(context, "ConnectedState")
    {
        context.user.showConnected();
    }

    void ConnectedState::handleDisconnected()
    {
        logger.logInfo("Connection to BTS lost");
        context.setState<NotConnectedState>();
    }

    void ConnectedState::handleSmsReceived(common::PhoneNumber from, std::string text) {
        logger.logInfo("SMS received from: ", from);
        std::size_t smsIndex = context.smsRepository.addSms(from, text);
        logger.logDebug("SMS stored at index: ", smsIndex);
        context.user.showNewSms();
    }
}