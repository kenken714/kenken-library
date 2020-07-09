bool solve(ll index, ll key) { //条件判定
	if (true) return true; //ここに条件を入れる
	else return false;
}

ll nibutan(ll key = 0) { //ちゃろー！

	ll ng = -1; //最大値ならs.size()
	ll ok = (ll)s.size(); // 最大値なら0

	while (abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;

		if (solve(mid, key)) ok = mid;
		else ng = mid;
	}
	return ok; //満たさない最大ならng
}