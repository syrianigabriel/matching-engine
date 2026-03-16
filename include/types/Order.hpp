#pragma once
#include <cstdint>
#include <iostream>
#include <list>
#include <map>

using Price = std::uint64_t;
using Quantity = std::uint64_t;
using OrderId = std::uint64_t;
using SeqNum = std::uint64_t;

enum class Side {
    BUY,
    SELL
};

struct Order {
    OrderId id;
    Side side;
    Price price;
    Quantity remaining_qty;
    Quantity initial_qty;
};

struct Trade {
    OrderId aggressor_order_id;
    OrderId resting_order_id;
    Quantity filled_qty;
    Price execution_price;
};

struct PriceLevel {
    Price price;
    std::list<Order> orders;
};

struct OrderLocation {
    Side side;
    Price price;
    std::list<Order>::iterator order_it;
};

struct OrderBook {
    std::map<Price, PriceLevel, std::greater<Price>> bids;
    std::map<Price, PriceLevel> asks;
    std::unordered_map<OrderId, OrderLocation> order_lookup;

    void add_order(Order order);
    std::vector<Trade> match_order(Order& incoming);
    void cancel_order(OrderId id);
};