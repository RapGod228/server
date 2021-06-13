/* Copyright (c) 2021, MariaDB Corporation

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1335  USA */

#include <mysql_version.h>
#include <mysql/plugin.h>
#include <lzma.h>
#include <wrappers/lzma.h>

static int init(void* h)
{
  wrapper_service_lzma->lzma_stream_buffer_decode_ptr= lzma_stream_buffer_decode;
  wrapper_service_lzma->lzma_easy_buffer_encode_ptr= lzma_easy_buffer_encode;
  return 0;
}

struct st_mysql_daemon info= { MYSQL_DAEMON_INTERFACE_VERSION  };

maria_declare_plugin(lzma)
{
  MYSQL_DAEMON_PLUGIN,
  &info,
  "lzma",
  "Sergei Golubchik",
  "LZMA compression service",
  PLUGIN_LICENSE_GPL,
  init,
  NULL,
  0x0100,
  NULL,
  NULL,
  "1.0",
  MariaDB_PLUGIN_MATURITY_STABLE
}
maria_declare_plugin_end;
