#ifndef UDPPACKET
#define UDPPACKET
#include <qbytearray.h>
typedef unsigned short ushort;
struct udp_header
{
    ushort src_port;
    ushort dst_port;
    ushort length;
    ushort crc;
    QString message;
    QByteArray toByteArray()
    {
        QByteArray temp("");
        temp.append(src_port);
        temp.append(dst_port);
        temp.append(length);
        temp.append(crc);
        temp.append(message);
        return temp;
    }
    int getLength()
    {
        QByteArray temp(message.toStdString().c_str());
        return temp.length();
    }
};


#endif // UDPPACKET

