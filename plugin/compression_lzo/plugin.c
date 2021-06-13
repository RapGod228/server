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
#include <lzo/lzo1x.h>
#include <compression/lzo/lzo1x.h>

static int init(void* h)
{
  compression_service_lzo->lzo1x_1_15_compress_ptr= lzo1x_1_15_compress;
  compression_service_lzo->lzo1x_decompress_safe_ptr= lzo1x_decompress_safe;
  return 0;
}

struct st_mysql_daemon info= { MYSQL_DAEMON_INTERFACE_VERSION  };

maria_declare_plugin(lzo)
{
  MYSQL_DAEMON_PLUGIN,
  &info,
  "lzo",
  "Sergei Golubchik",
  "LZO compression service",
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
