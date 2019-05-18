#include <iostream>
using namespace std;

template<typename T, T ...Xs>
struct List {};

template<typename T, T, typename>
struct Cons;
template<typename T, T c, typename L>
using Cons_t = typename Cons<T, c, L>::type;
template<typename T, T c, T ...Xs>
struct Cons<T, c, List<T, Xs...>> { using type = List<T, c, Xs...>; };

template<typename T, T c, typename ...Ch>
struct Pairing {};

template<bool, typename ...>
struct Merge2_;
template<bool b, typename ...Ts>
using Merge2__t = typename Merge2_<b, Ts...>::type;
template<typename T, T c1, typename ...Ch1, T c2, typename ...Ch2>
struct Merge2_<true, Pairing<T, c1, Ch1...>, Pairing<T, c2, Ch2...>> {
	using type = Pairing<T, c1, Ch1..., Pairing<T, c2, Ch2...>>;
};
template<typename T, T c1, typename ...Ch1, T c2, typename ...Ch2>
struct Merge2_<false, Pairing<T, c1, Ch1...>, Pairing<T, c2, Ch2...>> {
	using type = Pairing<T, c2, Ch2..., Pairing<T, c1, Ch1...>>;
};

template<typename, typename>
struct Merge2;
template<typename L, typename R>
using Merge2_t = typename Merge2<L, R>::type;
template<typename P>
struct Merge2<void, P> { using type = P; };
template<typename P>
struct Merge2<P, void> { using type = P; };
template<typename T, T c1, typename ...Ch1, T c2, typename ...Ch2>
struct Merge2<Pairing<T, c1, Ch1...>, Pairing<T, c2, Ch2...>> {
	using type = Merge2__t<(c1 < c2), Pairing<T, c1, Ch1...>, Pairing<T, c2, Ch2...>>;
};

template<typename ...>
struct Merge;
template<typename ...Ts>
using Merge_t = typename Merge<Ts...>::type;
template<>
struct Merge<> { using type = void; };
template<typename P>
struct Merge<P> { using type = P; };
template<typename T1, typename T2, typename ...Ts>
struct Merge<T1, T2, Ts...> {
	using type = Merge2_t<Merge2_t<T1, T2>, Merge_t<Ts...>>;
};

template<typename T, T ...Xs>
struct MakeHeap {
	using type = Merge_t<Pairing<T, Xs>...>;
};
template<typename T, T ...Xs>
using MakeHeap_t = typename MakeHeap<T, Xs...>::type;

template<typename, typename>
struct HeapSort_;
template<typename T, typename P>
using HeapSort__t = typename HeapSort_<T, P>::type;
template<typename T>
struct HeapSort_<T, void> { using type = List<T>; };
template<typename T, T c, typename ...Ch>
struct HeapSort_<T, Pairing<T, c, Ch...>> {
	using type = Cons_t<T, c, HeapSort__t<T, Merge_t<Ch...>>>;
};

template<typename T, T ...Xs>
struct HeapSort {
	using type = HeapSort__t<T, MakeHeap_t<T, Xs...>>;
};
template<typename T, T ...Xs>
using HeapSort_t = typename HeapSort<T, Xs...>::type;

// ========

template<typename T>
void prt(T);
template<typename T, T x, T ...Xs>
void prt(List<T, x, Xs...>) {
	cout << x << ' ';
	prt(List<T, Xs...>{});
}
template<typename T>
void prt(List<T>) { cout << endl; }

int main() {
	prt(HeapSort_t<int, 42>{});
	prt(HeapSort_t<int>{});
	prt(HeapSort_t<int, 42, 64, 36, 43, 53, 46, 26, 82, 45, 24, 14, 51, 24>{});
	return 0;
}