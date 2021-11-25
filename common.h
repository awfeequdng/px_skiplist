#ifndef __INCLUDE_TYPES_H__
#define __INCLUDE_TYPES_H__

#define MIN(_a, _b) 	\
({			\
 	typeof(_a) __a = (_a);	\
	typeof(_b) __b = (_b);	\
	__a <= __b ? __a : __b;	\
 })

#define MAX(_a, _b)	\
({			\
 	typeof(_a) __a = (_a);	\
	typeof(_b) __b = (_b);	\
	__a <= __b ? __b : __a;	\
})

#define ROUNDDOWN(a, n)	\
({			\
 	uint32_t __a = (uint32_t)(a);	\
	(typeof(a)) (__a - __a % (n));	\
})

#define ROUNDUP(a, n)	\
({			\
 	uint32_t __n = (uint32_t)(n);	\
 	(typeof(a)) (ROUNDDOWN((uint32_t)(a) + __n - 1, __n));	\
})

#define ROUNDUP_DIV(a, n)	\
({			\
 	uint32_t __n = (uint32_t)(n);	\
 	(typeof(a)) (((a) + __n - 1) / __n);	\
})

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#define offsetof(type, member) ((void*) (&((type*)0)->member))

#define container_of(ptr, type, member) ({	\
	typeof(((type *)0)->member) *__ptr = (ptr);	\
	(type *) ((void*)__ptr - offsetof(type, member));	\
})

#endif // __INCLUDE_TYPES_H__
