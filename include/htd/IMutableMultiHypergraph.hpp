/* 
 * File:   IMutableMultiHypergraph.hpp
 *
 * Author: ABSEHER Michael (abseher@dbai.tuwien.ac.at)
 * 
 * Copyright 2015-2016, Michael Abseher
 *    E-Mail: <abseher@dbai.tuwien.ac.at>
 * 
 * This file is part of htd.
 * 
 * htd is free software: you can redistribute it and/or modify it under 
 * the terms of the GNU General Public License as published by the Free 
 * Software Foundation, either version 3 of the License, or (at your 
 * option) any later version.
 * 
 * htd is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public 
 * License for more details.

 * You should have received a copy of the GNU General Public License
 * along with htd.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HTD_HTD_IMUTABLEMULTIHYPERGRAPH_HPP
#define	HTD_HTD_IMUTABLEMULTIHYPERGRAPH_HPP

#include <htd/Globals.hpp>
#include <htd/IMultiHypergraph.hpp>

namespace htd
{
    class IMutableMultiHypergraph : public virtual htd::IMultiHypergraph
    {
        public:
            /**
             *  Destructor for an IMutableMultiHypergraph object.
             */
            virtual ~IMutableMultiHypergraph() = 0;

            /**
             *  Add a new vertex to the multi-hypergraph.
             *
             *  @return The ID of the new vertex.
             */
            virtual htd::vertex_t addVertex(void) = 0;

            /**
             *  Add new vertices to the multi-hypergraph.
             *
             *  @param[in] count    The number of vertices which shall be added.
             *
             *  @return The ID of the first vertex which was added to the graph. If the number of vertices to add is greater than 1,
             *          the additional vertices are numbered in ascending order and without gaps starting from the returned ID + 1.
             *          If the number of new vertices is 0, the returned value is the ID of the last vertex added to the graph.
             */
            virtual htd::vertex_t addVertices(std::size_t count) = 0;

            /**
             *  Remove a vertex from the multi-hypergraph.
             *
             *  @param[in] vertex   The ID of the vertex which shall be removed.
             */
            virtual void removeVertex(htd::vertex_t vertex) = 0;

            /**
             *  Add a new edge to the multi-hypergraph.
             *
             *  @param[in] vertex1  The first endpoint of the edge.
             *  @param[in] vertex2  The second endpoint of the edge.
             *
             *  @return The ID of the new edge.
             */
            virtual htd::id_t addEdge(htd::vertex_t vertex1, htd::vertex_t vertex2) = 0;

            /**
             *  Add a new edge to the multi-hypergraph.
             *
             *  @param[in] elements The endpoints of the hyperedge.
             *
             *  @return The ID of the new edge.
             */
            virtual htd::id_t addEdge(const std::vector<htd::vertex_t> & elements) = 0;

            /**
             *  Add a new edge to the multi-hypergraph.
             *
             *  @param[in] elements The endpoints of the hyperedge.
             *
             *  @return The ID of the new edge.
             */
            virtual htd::id_t addEdge(std::vector<htd::vertex_t> && elements) = 0;

            /**
             *  Add a new edge to the multi-hypergraph.
             *
             *  @param[in] elements The endpoints of the hyperedge.
             *
             *  @return The ID of the new edge.
             */
            virtual htd::id_t addEdge(const htd::ConstCollection<htd::vertex_t> & elements) = 0;

            /**
             *  Add a new edge to the multi-hypergraph.
             *
             *  @param[in] hyperedge    The template hyperedge.
             *
             *  @return The ID of the new edge.
             */
            virtual htd::id_t addEdge(const htd::Hyperedge & hyperedge) = 0;

            /**
             *  Add a new edge to the multi-hypergraph.
             *
             *  @param[in] hyperedge    The template hyperedge.
             *
             *  @return The ID of the new edge.
             */
            virtual htd::id_t addEdge(htd::Hyperedge && hyperedge) = 0;

            virtual void removeEdge(htd::id_t edgeId) = 0;

            /**
             *  Create a deep copy the current mutable multi-hypergraph.
             *
             *  @return A new IMutableMultiHypergraph object identical to the current mutable multi-hypergraph.
             */
            virtual IMutableMultiHypergraph * clone(void) const = 0;

            /**
             *  Copy assignment operator for a mutable multi-hypergraph.
             *
             *  @param[in] original  The original multi-hypergraph.
             */
            virtual IMutableMultiHypergraph & operator=(const htd::IMultiHypergraph & original) = 0;
    };

    inline htd::IMutableMultiHypergraph::~IMutableMultiHypergraph() { }
}

#endif /* HTD_HTD_IMUTABLEMULTIHYPERGRAPH_HPP */
