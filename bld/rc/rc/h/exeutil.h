/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2002-2023 The Open Watcom Contributors. All Rights Reserved.
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  Executable processing utility function prototypes.
*
****************************************************************************/


#ifndef EXEUTIL_INCLUDED
#define EXEUTIL_INCLUDED

/* align should be a power of 2 */
/* without the casts the macro reads: (value + (align-1)) & ~(align-1) */
#define ALIGN_VALUE( value, align ) ( (uint_32)( \
        ( (uint_32)(value) + ( (uint_32)(align) - 1 ) ) \
        & ~( (uint_32)(align) - 1 ) ) )

#define ARE_BITS_EQUAL( mask, v1, v2 ) (!((mask) & ((v1)^(v2))))
/* returns 1 (true) if the bits identified by mask are equal in v1 and v2 */
/* otherwise returns 0 (false) */
/* note: if mask is 0 it always returns 1 (true) */

extern RcStatus     CopyExeData( FILE *in_fp, FILE *out_fp, uint_32 length );
extern long         AlignAmount( long offset, uint_16 shift_count );
extern uint_16      FindShiftCount( uint_32 filelen, uint_16 numobjs );
extern RcStatus     CopyExeDataTilEOF( FILE *in_fp, FILE *out_fp );
extern RcStatus     PadExeData( FILE *fp, long length );
extern void         CheckDebugOffset( ExeFileInfo * info );
extern RcStatus     SeekRead( FILE *fp, long newpos, void *buff, size_t size );
extern ExeType      FindNEPELXHeader( FILE *fp, unsigned_32 *ne_header_off );
extern unsigned_32  OffsetFromRVA( ExeFileInfo *info, pe_va rva );
extern bool         RcPadFile( FILE *fp, size_t pad );

#endif
