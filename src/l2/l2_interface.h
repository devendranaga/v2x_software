/**
 * @brief defines generic L2 virtual interface for the underlying driver
 *
 * @author Devendra Naga (devendra.aaru@outlook.com)
 * @copyright 2023-present All rights reserved.
 */
#ifndef __L2_INTERFACE_H__
#define __L2_INTERFACE_H__

#include <stdint.h>

namespace v2x::l2 {

struct l2_msg {
    uint8_t *msg;
    uint32_t msg_len;
};

enum l2_channel_type {
    AUTO,
    ALTERNATING,
    STATIC,
};

struct l2_interface_config {
    uint32_t channel;
    l2_channel_type channel_type;
    uint32_t transmit_power;
};

/**
 * Defines virtual interface for the underlying driver.
 */
class l2_interface {
    public:
        explicit l2_interface() = default;
        ~l2_interface() = default;

        virtual int init(l2_interface_config *conf) = 0;
        virtual int configure_channel(uint32_t channel,
                                      l2_channel_type channel_type) = 0;
        virtual int configure_txpower(uint32_t tx_power) = 0;
        virtual int transmit(l2_msg *msg,
                             l2_interface_config *conf) = 0;
        virtual int receive(l2_msg *msg,
                            l2_interface_config *conf) = 0;
        virtual void deinit() = 0;
};

}

#endif
