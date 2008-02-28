/***************************************************************************

 aNFS (ch_nfs) - Amiga NFS client
 Copyright (C) 1993-1994 Carsten Heyl
 Copyright (C) 2008      aNFS Open Source Team

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 aNFS OpenSource project:  http://sourceforge.net/projects/anfs/

 $Id$

***************************************************************************/

/*
 * Dir storing and retrieval functions.
 */

#define EDH_MAX_FILENAME_SIZE 108

/* structure containing information needed for ExNext calls */

typedef struct _edh
{
    struct _edh *edh_Next;
    LONG edh_Key;     /* key of scanned directory */
    ULONG edh_Cookie; /* amiga side cookie (fileid) */
    nfs_fh edh_NFSDirFh; /* nfs filehandle of diretory */
    nfscookie edh_NFSCookie;
    LONG edh_Eof; /* eof reached, NFSEntries points to last entries */
    entry *edh_NFSEntries;
    UBYTE edh_Name[EDH_MAX_FILENAME_SIZE];
} EDH;

#define NFS_READDIR_BUFSIZE 8000
