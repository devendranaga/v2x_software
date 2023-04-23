#ifndef __L2_INTERFACE_MGR_H__
#define __L2_INTERFACE_MGR_H__

#include <memory>
#include <l2_interface.h>

#include <raw_eth.h>

namespace v2x::l2 {

enum l2_interface_type {
    Raw_Eth,
};

class l2_interface_mgr {
    public:
        static l2_interface_mgr *instance() {
            static l2_interface_mgr mgr;
            return &mgr;
        }
        /* Allow callers to create raw network interface. */
        static std::unique_ptr<l2_interface> create(const l2_interface_type type) {
            if (type == l2_interface_type::Raw_Eth) {

            }

            return nullptr;
        }
        ~l2_interface_mgr() = default;

    private:
        explicit l2_interface_mgr() = default;
};

}

#endif
