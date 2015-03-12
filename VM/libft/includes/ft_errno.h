/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 16:16:13 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 16:16:14 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRNO_H
# define FT_ERRNO_H

# define FT_ERRNO (*(ft_errno__()))

# define FT_EPERM			1
# define FT_ENOENT			2
# define FT_ESRCH			3
# define FT_EINTR			4
# define FT_EIO			5
# define FT_ENXIO			6
# define FT_E2BIG			7
# define FT_ENOEXEC		8
# define FT_EBADF			9
# define FT_ECHILD			10
# define FT_EDEADLK		11
# define FT_ENOMEM			12
# define FT_EACCES			13
# define FT_EFAULT			14
# define FT_ENOTBLK		15
# define FT_EBUSY			16
# define FT_EEXIST			17
# define FT_EXDEV			18
# define FT_ENODEV			19
# define FT_ENOTDIR		20
# define FT_EISDIR			21
# define FT_EINVAL			22
# define FT_ENFILE			23
# define FT_EMFILE			24
# define FT_ENOTTY			25
# define FT_ETXTBSY		26
# define FT_EFBIG			27
# define FT_ENOSPC			28
# define FT_ESPIPE			29
# define FT_EROFS			30
# define FT_EMLINK			31
# define FT_EPIPE			32
# define FT_EDOM			33
# define FT_ERANGE			34
# define FT_EAGAIN			35
# define FT_EWOULDBLOCK	EAGAIN
# define FT_EINPROGRESS	36
# define FT_EALREADY		37
# define FT_ENOTSOCK		38
# define FT_EDESTADDRREQ	39
# define FT_EMSGSIZE		40
# define FT_EPROTOTYPE		41
# define FT_ENOPROTOOPT	42
# define FT_EPROTONOSUPPORT	43
# define FT_ESOCKTNOSUPPORT	44
# define FT_ENOTSUP		45
# define FT_EPFNOSUPPORT	46
# define FT_EAFNOSUPPORT	47
# define FT_EADDRINUSE		48
# define FT_EADDRNOTAVAIL	49
# define FT_ENETDOWN		50
# define FT_ENETUNREACH	51
# define FT_ENETRESET		52
# define FT_ECONNABORTED	53
# define FT_ECONNRESET		54
# define FT_ENOBUFS		55
# define FT_EISCONN		56
# define FT_ENOTCONN		57
# define FT_ESHUTDOWN		58
# define FT_ETOOMANYREFS	59
# define FT_ETIMEDOUT		60
# define FT_ECONNREFUSED	61
# define FT_ELOOP			62
# define FT_ENAMETOOLONG	63
# define FT_EHOSTDOWN		64
# define FT_EHOSTUNREACH	65
# define FT_ENOTEMPTY		66
# define FT_EPROCLIM		67
# define FT_EUSERS			68
# define FT_ESTALE			70
# define FT_EREMOTE		71
# define FT_EBADRPC		72
# define FT_ERPCMISMATCH	73
# define FT_EPROGUNAVAIL	74
# define FT_EPROGMISMATCH	75
# define FT_EPROCUNAVAIL	76
# define FT_ENOLCK			77
# define FT_ENOSYS			78
# define FT_EFTYPE			79
# define FT_EAUTH			80
# define FT_ENEEDAUTH		81
# define FT_EPWROFF		82
# define FT_EDEVERR		83
# define FT_EOVERFLOW		84
# define FT_EBADEXEC		85
# define FT_EBADARCH		86
# define FT_ESHLIBVERS		87
# define FT_EBADMACHO		88
# define FT_ECANCELED		89
# define FT_EIDRM			90
# define FT_ENOMSG			91
# define FT_EILSEQ			92
# define FT_ENOATTR		93
# define FT_EBADMSG		94
# define FT_EMULTIHOP		95
# define FT_ENODATA		96
# define FT_ENOLINK		97
# define FT_ENOSR			98
# define FT_ENOSTR			99
# define FT_EPROTO			100
# define FT_ETIME			101
# define FT_EOPNOTSUPP		102
# define FT_ENOPOLICY		103
# define FT_ENOTRECOVERABLE	104
# define FT_EOWNERDEAD		105
# define FT_EQFULL			106
# define FT_ELAST			106

int		*ft_errno__(void);
char	*strerror(int errnum);

#endif
