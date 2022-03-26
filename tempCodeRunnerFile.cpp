po::variables_map vm;
    // po::store(po::parse_command_line(argc, argv, desc), vm);
    // po::notify(vm);
    
    // if (vm.count("help")) {
    //     std::cout << desc << std::endl;
    //     return 1;
    // }
    

    // if (!vm.count("corpus_dir")) {
    //     std::cout << "Error: corpus_dir must be provided!" << std::endl;
    //     std::cout << desc << std::endl;
    //     return 1;
    // }

    // corpus_dir = vm["corpus_dir"].as<std::string>();
    
    // rp::LSH lsh(mh_sig_len,lsh_bands,ngram_len);
    // std::cerr << "parameters:" << mh_sig_len << " | " << lsh_bands << " | " << ngram_len << std::endl;
    
    
    // std::cerr << "Computing minhash for files in : " << corpus_dir << std::endl;
    // lsh.minhash_corpus(corpus_dir,true,true);
    // std::ofstream of;
    // of.open("minhash_sigs.csv");
    // rp::MinHashMap mh_map = lsh.get_minhash_signatures();
    // for (rp::MinHashMap::value_type itm : mh_map) {
    //     of << itm.first;
    //     for(uint32_t v : itm.second)
    //         of << ", " << v;
    //     of << std::endl;
    // }
    // of.close();
    
    // std::cerr << "Computing bands  " << lsh_bands << std::endl;
    // lsh.compute_bands();
    // std::cerr << "Computing candidates " << std::endl;
    // lsh.compute_candidate_pairs();
    // std::vector<rp::CandidatePair> cpv = lsh.get_candidate_pairs();
    
    // std::cerr << "Computing minhash similarity: " << cpv.size() << std::endl;
    // lsh.compute_minhash_similarities();
    // of.open("minhash_sim.csv");
    // std::vector<float> jsvmh = lsh.get_minhash_similarities();
    // for(int i=0; i<cpv.size(); i++)
    //     of << cpv[i].first << "," << cpv[i].second << "," << jsvmh[i] << std::endl;
    // of.close();
    
    // // we can also compute the similarity based on the 
    // // original document ngrams
    // // this is available if lsh.minhash_corpus() was called with keep_ngrams set to true
    // of.open("ngram_sim.csv");
    // std::cerr << "Computing ngram similarity: " << cpv.size() << std::endl;
    // lsh.compute_ngram_similarities();
    // std::vector<float> jsvng = lsh.get_ngram_similarities();
    // for(int i=0; i<cpv.size(); i++)
    //     of << "ngram: " << cpv[i].first << "," << cpv[i].second << "," << jsvng[i] << std::endl;
    // of.close();