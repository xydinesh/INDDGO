/*
  This file is part of INDDGO.

  Copyright (C) 2012, Oak Ridge National Laboratory 

  This product includes software produced by UT-Battelle, LLC under Contract No. 
  DE-AC05-00OR22725 with the Department of Energy. 

  This program is free software; you can redistribute it and/or modify
  it under the terms of the New BSD 3-clause software license (LICENSE). 
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
  LICENSE for more details.

  For more information please contact the INDDGO developers at: 
  inddgo-info@googlegroups.com

*/

#include "GraphCreatorFile.h"
#include "Graph.h"
#include "WeightedGraph.h"
#include "GraphException.h"
#include <iostream>

namespace Graph
{
	GraphCreatorFile::GraphCreatorFile()
	{
		this->factory_rw = new GraphReaderWriterFactory();
	}

	GraphCreatorFile::GraphCreatorFile(string file, string graphType)
	{
		this->factory_rw = new GraphReaderWriterFactory();
		this->file_name = file;
		this->graph_type = graphType;
	}

	GraphCreatorFile::~GraphCreatorFile()
	{
		delete this->factory_rw;
	}

	string GraphCreatorFile::get_file_name() const
	{
		return file_name;
	}

	string GraphCreatorFile::get_graph_type() const
	{
		return graph_type;
	}

	void GraphCreatorFile::set_file_name(string fileName)
	{
		this->file_name = fileName;
	}

	WeightedGraph* GraphCreatorFile::create_weighted_graph()
	{
		WeightedGraph *wg = new WeightedGraph();
		GraphReader *gr = factory_rw->create_reader(graph_type);

        try 
        {
            gr->read_graph(file_name.c_str());
            wg->set_input_file(file_name);
            wg->set_degree(gr->get_degree());
            wg->set_nodes(gr->get_nodes());
            wg->set_num_edges(gr->get_num_edges());
            wg->set_num_nodes(gr->get_nodes().size());
            wg->set_capacity(gr->get_capacity());
            wg->set_next_label(gr->get_capacity() + 1);
            wg->set_graph_type(graph_type);
            wg->set_weight(gr->get_weights());
        }
        catch(GraphException& e)
        {
            delete gr;
            delete wg;
            cerr << "exception caught: " << e.what() << endl;
            const string desc("Can not create a weighted graph\n");
            throw GraphException(desc);
        }

        delete gr;
        return wg;
	}

	MutableGraph* GraphCreatorFile::create_mutable_graph()
	{
		MutableGraph *mg = new MutableGraph();
		GraphReader *gr = factory_rw->create_reader(graph_type);

        try
        {
            gr->read_graph(file_name.c_str());
            mg->set_input_file(file_name);
            mg->set_degree(gr->get_degree());
            mg->set_nodes(gr->get_nodes());
            mg->set_num_edges(gr->get_num_edges());
            mg->set_num_nodes(gr->get_nodes().size());
            mg->set_capacity(gr->get_capacity());
            mg->set_next_label(gr->get_capacity() + 1);
            mg->resize_adj_vec(gr->get_capacity());
            mg->set_graph_type(graph_type);
        }
        catch(GraphException& e)
        {
            delete gr;
            delete mg;
            cerr << "exception caught: " << e.what() << endl;
            const string desc("Can not create a mutable graph\n");
            throw GraphException(desc);
        }

        delete gr;
		return mg;
	}

	WeightedMutableGraph* GraphCreatorFile::create_weighted_mutable_graph()
	{
		WeightedMutableGraph *wmg = new WeightedMutableGraph();
		GraphReader *gr = factory_rw->create_reader(graph_type);
        
        try
        {
            gr->read_graph(file_name.c_str());
            wmg->set_input_file(file_name);
            wmg->set_degree(gr->get_degree());
            wmg->set_nodes(gr->get_nodes());
            wmg->set_num_edges(gr->get_num_edges());
            wmg->set_num_nodes(gr->get_nodes().size());
            wmg->set_capacity(gr->get_capacity());
            wmg->set_next_label(gr->get_capacity() + 1);
            wmg->resize_adj_vec(gr->get_capacity());
            wmg->set_graph_type(graph_type);
            wmg->set_weight(gr->get_weights());
        }
        catch(GraphException& e)
        {
            delete wmg;
            delete gr;
            cerr << "exception caught: " << e.what() << endl;
            const string desc("Can not create a weighted mutable graph\n");
            throw GraphException(desc);
        }
        
        delete gr;
        return wmg;
	}

	void GraphCreatorFile::set_graph_type(string graphType)
	{
		this->graph_type = graphType;
	}

	Graph* GraphCreatorFile::create_graph()
	{
		Graph *g = new Graph();
		GraphReader *gr = factory_rw->create_reader(graph_type);

        try
        {
            gr->read_graph(file_name.c_str());
            g->set_input_file(file_name);
            g->set_degree(gr->get_degree());
            g->set_nodes(gr->get_nodes());
            g->set_num_edges(gr->get_num_edges());
            g->set_num_nodes(gr->get_nodes().size());
            g->set_capacity(gr->get_capacity());
            g->set_next_label(gr->get_capacity() + 1);
            g->set_graph_type(graph_type);
        }
        catch(GraphException& e)
        {
            delete gr;
            delete g;
            cerr << "exception caught: " << e.what() << endl;
            const string desc("Can not create a graph\n");
            throw GraphException(desc);
        }

        delete gr;
		return g;
	}
}
