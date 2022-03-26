#include "lshensemble.hpp"
#include "lsh"


LshEnsemble NewLshEnsemble(Partition *parts, int numHash, int maxK){
    Lsh lshes[numPart];
	for(int i = 0; i < numPart; i++){
		lshes[i] = new LshForest(maxK, numHash/maxK);
	}
	return LshEnsemble{parts, lshes, maxK, numHash};
	
}

// LshEnsemble NewLshEnsemblePlus(Partition *parts, int numHash, int maxK){
//     Lsh lshes[numPart];
//     for(int i = 0; i < numPart; i++){
//             lshes[i] = NewLshForestArray(maxK, numHash);
//         }
//         return LshEnsemble{parts, lshes, maxK, numHash};
// }


void LshEnsemble::add(std::string key, u_int32_t sig[], int partInd){
    this->lshes[partInd].add(key, sig);
}

void LshEnsemble::prepare(std::string key, u_int32_t *sig, int size)  {
	for(int i = 0; i < numPart; i++){
		if (size >= this->partitions[i].lower && size <= this->partitions[i].upper) {
			this->add(key, sig, i);
			break;
		}
	}
	std::cerr << "no matching partition \n";
}

void LshEnsemble::index(){
    for(int i = 0; i < numPart; i++){
        this->lshes[i].index();
    }
}

std::vector<std::string> LshEnsemble::query(u_int32_t *sig, int size, double threshold){
    Param *params = this->computeParams(size, threshold);
    clock_t begin = clock();
    std::vector<std::string> results;
    results = this->queryWithParam(sig, params);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    return results;
}

std::vector<std::string> LshEnsemble::queryWithParam(u_int32_t *sig, Param *params){
    std::vector<std::string> results, tmp;
    for(int i = 0; i < numPart; i++){
        tmp = this->lshes[i].query(sig, params[i].k, params[i].l);
        results.insert(results.end(), tmp.begin(), tmp.end());
    }
    return results;
}

Param* LshEnsemble::computeParams(int size, double threshold){
    Param params[numPart], optP;
    int x ,p;
    for(int i = 0; i < numPart; i++){
        x = this->partitions[i].upper;
        Key key{x, size, threshold};
        if(this->cmap.count(key)){
            params[i] = this->cmap[key];
        }else{
            optP = this->lshes[i].optimalKL(x, size, threshold);
            this->cmap[key] = optP;
            params[i] = optP;
        }
    }
    return params;
}

hashKeyFunc hashKeyFuncGen(int hashValueSize){

}

