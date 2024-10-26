#ifndef QRC_DECODER_H
#define QRC_DECODER_H

#include <utils/buffer.h>

namespace qqmusic
{
    enum class result
    {
        qrc_decode_ok,
        mem_alloc_error,
        data_destroy,
        unknown_error
    };

    namespace utils
    {
        enum class qrc_type
        {
            cloud,
            local
        };

        qqmusic::result qrc_decode(qqmusic::utils::buffer* src,
                                   qqmusic::utils::buffer* dest,
                                   qqmusic::utils::qrc_type type);
    }

}

#endif
