#pragma once

#include "Ports/ITimerPort.hpp"
#include "Ports/IBtsPort.hpp"
#include "Ports/IUserPort.hpp"
#include "Messages/PhoneNumber.hpp"
#include <optional>


namespace ue {
    namespace details {
        using GuiViewMode = int;
        constexpr GuiViewMode VIEW_MODE_UNKNOWN = 0;
        constexpr GuiViewMode VIEW_MODE_MAIN_MENU = 1;
        constexpr GuiViewMode VIEW_MODE_SMS_LIST = 2;
        constexpr GuiViewMode VIEW_MODE_SMS_VIEW = 3;
        constexpr GuiViewMode VIEW_MODE_SMS_COMPOSE = 4;
        constexpr GuiViewMode VIEW_MODE_SMS_MENU = 5;
        constexpr GuiViewMode VIEW_MODE_DIAL = 6;
    }

    class IEventsHandler : public IBtsEventsHandler,
                           public IUserEventsHandler,
                           public ITimerEventsHandler
    {
    public:
        virtual ~IEventsHandler()  = default;

        virtual void handleUiAction(std::optional<std::size_t> selectedIndex) = 0;
        virtual void handleUiBack() = 0;
        virtual void handleSmsComposeResult(common::PhoneNumber recipient, const std::string& text) = 0;
        virtual void handleCallRequest(common::PhoneNumber from) = 0;
        virtual void handleCallDropped(common::PhoneNumber peer) = 0;
        virtual void handleUnknownRecipient(common::PhoneNumber peer) = 0;
        virtual void handleCallTalk(common::PhoneNumber from, const std::string &text) = 0;
        virtual void handleCallReject(common::PhoneNumber from) = 0;
    };


}