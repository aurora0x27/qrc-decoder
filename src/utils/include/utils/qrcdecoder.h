#ifndef QRC_DECODER_H
#define QRC_DECODER_H

#include <optional>
#include <string>
#include <utils/buffer.h>

namespace qqmusic {

using result = std::optional<std::string>;

namespace utils {
enum class qrc_type { cloud, local };

qqmusic::result qrc_decode(const qqmusic::utils::buffer& src,
                           qqmusic::utils::buffer& dest,
                           qqmusic::utils::qrc_type type);
} // namespace utils

} // namespace qqmusic

#endif
