<main>
        <h2 class="ca">Products Available </h2>
        <div class="container">
            <% if (posts && posts.length === 0) { %>
                <p class="caa">No products available at present.</p>
            <% } else { %>
                <% posts.forEach(post => { %>
                    <div class="post card mb-3">
                        <% if (post.image_url) { %>
                            <img src="<%= post.image_url %>" alt="<%= post.title %>">
                        <% } %>
                        <div class="post-content">
                            <h3 class="card-title"><%= post.title %></h3>
                            <p class="card-text"><%= post.content %></p>
                            <p><strong>Mobile Number:</strong> <%= post.mobile_number %></p>
                        <p><strong>Email Address:</strong> <%= post.email_address %></p>
                        <p><strong>Expected Amount:</strong> $<%= post.expected_amount %></p>
                        </div>
                        <div class="post-actions">
                            <a href="/edit/<%= post.id %>" class="btn btn-primary">Edit</a>
                            <form action="/delete/<%= post.id %>" method="POST" style="display:inline;">
                                <button type="submit" class="btn btn-danger">Delete</button>
                            </form>
                        </div>
                    </div>
                <% }) %>
            <% } %>
        </div>
    </main>