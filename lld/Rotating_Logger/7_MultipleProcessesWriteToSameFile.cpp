#include <sys/file.h>
#include <fcntl.h>
#include <unistd.h>

void safeAppend(const std::string& filename, const std::string& msg) {
    int fd = open(filename.c_str(), O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fd < 0) return;

    flock(fd, LOCK_EX);
    write(fd, msg.c_str(), msg.size());
    write(fd, "\n", 1);
    flock(fd, LOCK_UN);
    close(fd);
}

