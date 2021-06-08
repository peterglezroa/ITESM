% Pedro Luis González Roa
% A01651517
% Project 2: Stochastic matrices

% Allow user to use random or create own matrix
disp("Stochastic matrices\n");
valid_m = false;
while ~valid_m
    option = input("\nWould you like to use a random matrix (1)? or define your matrix? (2): ");
    if option == 1
        % Create automatically a 3x3 random stochastic matrix
        M = zeros(3,3);
        for i = 1:3
            M(i, 1) = rand();
            M(i, 2) = rand();
            while M(i, 1) + M(i, 2) > 1
                M(i, 2) = rand();
            end
            M(i, 3) = 1 - (M(i, 1) + M(i, 2));
        end
        disp(M);
    elseif option == 2
        % Allow user to create his own N x N matrix
        valid = false;
        while ~valid
            M = input("Give me your matrix:\n");
            disp(M);

            [n,n2] = size(M);
            if n ~= n2
                disp("Not a valid matrix: The number of columns must be the same as the rows. Try again.\n");
            else
                valid = true;
            end
        end
    else
        disp("Not a valid option!\n")
    end
    
    % Check that it is a valid stochastic matrix
    valid_m = true;
    disp("Checking if it is a right stochastic matrix....");
    [n, n2] = size(M);
    % Check if it is a row based stochastic matrix
    for i = 1:n % rows
        sm = 0;
        for j = 1:n % colums
            sm = sm + M(i,j);
        end
        if sm ~= 1
            disp("This is not a right stochastic matrix!");
            valid_m = false;
            break;
        end
    end
    % Check if it is a column based stochastic matrix
    if valid_m
        disp("This is a right stochastic matrix!");
    else
        valid_m = true;
        disp("Checking if it is a left stochastic matrix....");
        for i = 1:n
            for j = 1:n
                sm = sm + M(j,i);
            end
            if sm ~= 1
                disp("This is not a left stochastic matrix...");
                valid_m = false;
                break; 
            end
        end
        if valid_m
            disp("This is a left stochastic matrix!");
            M = M';
        end
    end
end

% Calculate the probability from going to one state to another in n steps.
steps = input("\n\nHow many steps would you like to test? ");
MS = M;
for i = 1:steps
    fprintf("Step #%d:", i);
    MS = MS*M;
    display(MS);
end

% Identify if the matrix is regular or not
had_zeros = false;
is_regular = false;
for i = 1:n
    for j = 1:n
        if M(i,j) == 0
            had_zeros = true;
            if M(i,j) ~= MS(i,j)
                is_regular = true;
                break;
            end
        end
    end
end
if is_regular || ~had_zeros
    disp("This is a regular matrix!");
    % Calculate the long-term state of the matrix, Indicate the minimum needed
    % value for the power (if there is no steady state notify the user)
    E = eig(M');
    if E(1) == 1
        [V,D] = eig(M');
        V1 = V(:,1)';
        disp("The long-term state of the matrix is: ");
        disp(V1/sum(V1));
    else
        disp("Could not find a steady state");
    end
else
    disp("This is not a regular matrix!");
end