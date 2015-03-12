/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 19:33:06 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 19:33:06 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_errno.h"

static char		*g_error[FT_ELAST] =
{
	"Undefined error: 0",
	"Operation not permitted",
	"No such file or directory",
	"No such process",
	"Interrupted system call",
	"Input/output error",
	"Device not configured",
	"Argument list too long",
	"Exec format error",
	"Bad file descriptor",
	"No child processes",
	"Resource deadlock avoided",
	"Cannot allocate memory",
	"Permission denied",
	"Bad address",
	"Block device required",
	"Device / Resource busy",
	"File exists",
	"Cross-device link",
	"Operation not supported by device",
	"Not a directory",
	"Is a directory",
	"Invalid argument",
	"Too many open files in system",
	"Too many open files",
	"Inappropriate ioctl for device",
	"Text file busy",
	"File too large",
	"No space left on device",
	"Illegal seek",
	"Read-only file system",
	"Too many links",
	"Broken pipe",
	"Numerical argument out of domain",
	"Result too large",
	"Resource temporarily unavailable",
	"Operation would block",
	"Operation now in progress",
	"Operation already in progress",
	"Socket operation on non-socket",
	"Destination address required",
	"Message too long",
	"Protocol wrong type for socket",
	"Protocol not available",
	"Protocol not supported",
	"Socket type not supported",
	"Operation not supported",
	"Protocol family not supported",
	"Address family not supported by protocol family",
	"Address already in use",
	"Can't assign requested address",
	"Network is down",
	"Network is unreachable",
	"Network dropped connection on reset",
	"Software caused connection abort",
	"Connection reset by peer",
	"No buffer space available",
	"Socket is already connected",
	"Socket is not connected",
	"Can't send after socket shutdown",
	"Too many references: can't splice",
	"Operation timed out",
	"Connection refused",
	"Too many levels of symbolic links",
	"File name too long",
	"Host is down",
	"No route to host",
	"Directory not empty",
	"Too many processes",
	"Too many users",
	"Stale NFS file handle",
	"Too many levels of remote in path",
	"RPC struct is bad",
	"RPC version wrong",
	"RPC prog. not avail",
	"Program version wrong",
	"Bad procedure for program",
	"No locks available",
	"Function not implemented",
	"Inappropriate file type or format",
	"Authentication error",
	"Need authenticator"
};

char			*strerror(int errnum)
{
	if (errnum > FT_ELAST || errnum < 0)
		return ((void *)0);
	return (g_error[errnum]);
}
