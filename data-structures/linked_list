#ifndef LINKED_LIST_GENERATORH
#define LINKED_LIST_GENERATORH

#include <stddef.h>
#include <stdlib.h>

#define PROTOTYPE_LINKED_LIST(name, type)				\
									\
	struct name##_elem;						\
	typedef struct name##_elem *name##_elem_t;			\
									\
	struct name##_elem {						\
		name##_elem_t next;					\
		type *val;						\
	};								\
									\
	struct name;							\
	typedef struct name *name##_t;					\
									\
	struct name {							\
		size_t size;						\
		name##_elem_t first;					\
		name##_elem_t last;					\
		name##_t (*push_front)(name##_t, type *);		\
		name##_t (*push_back)(name##_t, type *);		\
		type *(*pop_front)(name##_t);				\
		type *(*pop_back)(name##_t);				\
		void (*foreach)(name##_t, void (*fct)(type *));		\
		type *(*at)(name##_t, size_t);				\
	};								\
									\
	name##_t new_##name(void);					\
	void delete_##name(name##_t);					\
	name##_t push_front_##name(name##_t, type *);			\
	name##_t push_back_##name(name##_t, type *);			\
	type *pop_front_##name(name##_t);				\
	type *pop_back_##name(name##_t);				\
	void foreach_##name(name##_t, void(*f)(type *));		\
	type *at_##name(name##_t, size_t at);				\

#define DECLARE_LINKED_LIST(name, type)					\
	name##_t new_##name(void)					\
	{								\
		name##_t list = malloc(sizeof(struct name));		\
									\
		if (list == NULL)					\
			return (NULL);					\
		list->first = NULL;					\
		list->last = NULL;					\
		list->size = 0;						\
		list->push_front = &push_front_##name;			\
		list->push_back = &push_back_##name;			\
		list->pop_front = &pop_front_##name;			\
		list->pop_back = &pop_back_##name;			\
		list->foreach = &foreach_##name;			\
		list->at = &at_##name;					\
		return (list);						\
	}								\
									\
	void delete_##name(name##_t list)				\
	{								\
		name##_elem_t elem = list->first;			\
		name##_elem_t tmp;					\
									\
		while (elem != NULL) {					\
			tmp = elem;					\
			elem = elem->next;				\
			free(elem);					\
		}							\
		free(list);						\
	}								\
									\
	name##_t push_front_##name(name##_t list, type *val)		\
	{								\
		name##_elem_t elem = malloc(sizeof(struct name##_elem)); \
									\
		if (elem == NULL)					\
			return (NULL);					\
		elem->val = val;					\
		elem->next = list->first;				\
		list->first = elem;					\
		list->size++;						\
		return (list);						\
	}								\
									\
	name##_t push_back_##name(name##_t list, type *val)		\
	{								\
		name##_elem_t elem = malloc(sizeof(struct name##_elem)); \
		name##_elem_t tmp;					\
									\
		if (elem == NULL)					\
			return (NULL);					\
		elem->val = val;					\
		elem->next = NULL;					\
		if (list->first == NULL)				\
			list->first = elem;				\
		else {							\
			tmp = list->first;				\
			while (tmp->next != NULL)			\
				tmp = tmp->next;			\
			tmp->next = elem;				\
		}							\
		list->size++;						\
		return (list);						\
	}								\
									\
	type *pop_front_##name(name##_t list)				\
	{								\
		name##_elem_t elem;					\
		type *val;						\
									\
		if (list->first == NULL)				\
			return (NULL);					\
		elem = list->first->next;				\
		val = list->first->val;					\
		free(list->first);					\
		list->first = elem;					\
		list->size--;						\
		return (val);						\
	}								\
									\
	type *pop_back_##name(name##_t list)				\
	{								\
		name##_elem_t elem = list->first;			\
		type *val;						\
									\
		if (elem == NULL)					\
			return (NULL);					\
		if (elem->next == NULL) {				\
			val = elem->val;				\
			free(list->first);				\
			list->first = NULL;				\
		}							\
		else {							\
			elem = list->first;				\
			while (elem->next->next)			\
				elem = elem->next;			\
			val = elem->next->val;				\
			free(elem->next);				\
			elem->next = NULL;				\
		}							\
		list->size--;						\
		return (val);						\
	}								\
									\
	void foreach_##name(name##_t list, void (*fct)(type *))		\
	{								\
		name##_elem_t elem = list->first;			\
									\
		while (elem != NULL) {					\
			fct(elem->val);					\
			elem = elem->next;				\
		}							\
	}								\
									\
	type *at_##name(name##_t list, size_t at)			\
	{								\
		name##_elem_t elem = list->first;			\
		size_t i;						\
									\
		for (i = 0; i < at; i++) {				\
			elem = elem->next;				\
		}							\
		return (i != at ? NULL : elem->val);			\
	}								\

#endif
