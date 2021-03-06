/******************************************************************************
 * Copyright (C) 2016 Felix Rohrbach <kde@fxrh.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#pragma once

#include "event.h"

namespace QMatrixClient
{
    struct Receipt
    {
        QString userId;
        QDateTime timestamp;
    };
    struct ReceiptsForEvent
    {
        QString evtId;
        std::vector<Receipt> receipts;
    };
    using EventsWithReceipts = std::vector<ReceiptsForEvent>;

    class ReceiptEvent: public Event
    {
        public:
            explicit ReceiptEvent(const QJsonObject& obj);

            EventsWithReceipts eventsWithReceipts() const
            { return _eventsWithReceipts; }
            bool unreadMessages() const { return _unreadMessages; }

            static constexpr const char* const TypeId = "m.receipt";

        private:
            EventsWithReceipts _eventsWithReceipts;
            bool _unreadMessages; // Spec extension for caching purposes

            static constexpr const char * jsonType = "m.receipt";
    };
}  // namespace QMatrixClient
