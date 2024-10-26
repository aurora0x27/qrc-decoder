# QRC-Decoder

This repo includes a function to decode QRC-Lyrics(Lyric file format of QQMusic) and output into binary buffer.

## Usage

The declaration of function is:

```cpp
qqmusic::result qrc_decode(qqmusic::utils::buffer* src,
                           qqmusic::utils::buffer* dest,
                           qqmusic::utils::qrc_type type);
```

Its input format and output format is `qqmusic::utils::buffer`.

A small program is also provided to decode qrc lyric conveniently

## Main logic

The working principle of this decoder:

```
judge type:
|
|\
| if is local qmc_decrypt and delete 11 bytes at head of buffer
| |
if is cloud: do nothing
|/
|
3des decode
|
zlib decompress
```

## Reference

[luren-dc QQMusicApi](https://github.com/luren-dc/QQMusicApi)

[LDDC](https://github.com/chenmozhijin/LDDC)
