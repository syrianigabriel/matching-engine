#include <Order.hpp>

void OrderBook::add_order(Order order)
{
    if (order.side == Side::BUY) {
        PriceLevel& level = bids[order.price];
        level.orders.push_back(order);
    } else {
        PriceLevel& level = asks[order.price];
        level.orders.push_back(order); 
    }
}



std::vector<Trade> match_order(Order& incoming)
{
}


void cancel_order(OrderId id);
{
}