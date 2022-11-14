/* Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "hal_file.h"

#include "fcntl.h"
#include "fs.h"

__attribute__((weak)) int HalFileOpen(const char *path, int oflag, int mode)
{
    (void)mode;
    return open(path, oflag);
}

__attribute__((weak)) int HalFileClose(int fd)
{
    return close(fd);
}

__attribute__((weak)) int HalFileRead(int fd, char *buf, unsigned int len)
{
    return read(fd, buf, len);
}

__attribute__((weak)) int HalFileWrite(int fd, const char *buf, unsigned int len)
{
    return write(fd, buf, len);
}

__attribute__((weak)) int HalFileDelete(const char *path)
{
    return unlink(path);
}

__attribute__((weak)) int HalFileStat(const char *path, unsigned int *fileSize)
{
    struct stat info = { 0 };
    int ret = stat(path, &info);
    if (ret < 0) {
        return ret;
    } else {
        return info.st_size;
    }
}

__attribute__((weak)) int HalFileSeek(int fd, int offset, unsigned int whence)
{
    return lseek(fd, offset, whence);
}